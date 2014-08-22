/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */

/*
  $Id$

  Author(s):  Zihan Chen

  (C) Copyright 2014 Johns Hopkins University (JHU), All Rights Reserved.

--- begin cisst license - do not edit ---

This software is provided "as is" under an open source license, with
no warranty.  The complete license can be found in license.txt and
http://www.cisst.org/cisst/license.txt.

--- end cisst license ---
*/


#ifndef __Eth1394Port_H__
#define __Eth1394Port_H__

#include "pcap.h"
#include "FirewirePort.h"

class Eth1394Port : public FirewirePort
{
public:
    enum { MAX_NODES = 15 };  // max number of boards, limited by rotary switch

protected:

    //! FireWire tcode
    enum TCODE {
        QWRITE = 0,
        BWRITE = 1,
        QREAD = 4,
        BREAD = 5,
        QRESPONSE = 6,
        BRESPONSE = 7
    };


    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    const u_char *packet;		/* The actual packet */
    struct pcap_pkthdr header;	/* The header that pcap gives us */
    pcap_t *handle;
    u_int16_t frame_hdr[7];

    // read FPGA node

    /**
     * @brief
     *
     * @param node
     * @param addr
     * @param length
     * @param buffer
     *
     * @return int 0 on success, -1 on failure
     */
    int eth1394_read(nodeid_t node, nodeaddr_t addr, size_t length, quadlet_t* buffer);

    /**
     * @brief
     *
     * @param node
     * @param addr
     * @param length
     * @param buffer
     *
     * @return int 0 on success, -1 on failure
     */
    int eth1394_write(nodeid_t node, nodeaddr_t addr, size_t length, quadlet_t* buffer);

    // write number of FPGA boards on the bus
    int eth1394_write_nodenum(int num);

    // Initialize Firewire port
    bool Init(void);

    // Look for nodes on the bus
    bool ScanNodes(void);

public:
    Eth1394Port(int portNum, std::ostream &debugStream = std::cerr);

    int GetNodeId(unsigned char boardId) const;
    unsigned long GetFirmwareVersion(unsigned char boardId) const;

    // Read all boards
    bool ReadAllBoards(void);

    // Write to all boards
    bool WriteAllBoards(void);

    // Read a quadlet from the specified board
    bool ReadQuadlet(unsigned char boardId, nodeaddr_t addr, quadlet_t &data);

    // Write a quadlet to the specified board
    bool WriteQuadlet(unsigned char boardId, nodeaddr_t addr, quadlet_t data);

    // Read a block from the specified board
    bool ReadBlock(unsigned char boardId, nodeaddr_t addr, quadlet_t *data,
                   unsigned int nbytes);

    // Write a block to the specified board
    bool WriteBlock(unsigned char boardId, nodeaddr_t addr, quadlet_t *data,
                    unsigned int nbytes);
};

#endif  // __Eth1394Port_H__

