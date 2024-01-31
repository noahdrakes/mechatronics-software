# FOR MACOS
pids=$(lsof -t -i :12345)

# Check if any PIDs were found
if [ -n "$pids" ]; then
    # Kill the processes using the specified PIDs
    kill -9 $pids
    echo "Processes terminated."
else
    echo "No processes found using the specified port."
fi