# Bash script used to kill all processing running on the same ethernet port (FOR PROCESSOR)
# script should sit on the processor 
# Issue: when the ethernet_client.cpp and ethernet_server.cpp programs are finished executing, 
# the process still runs in the background, disallowing the program to run again and hang when trying to connect to the socket

# TODO: figure out how to truly close this process when the executable is finished running

sudo pkill -9 -f ":12345"