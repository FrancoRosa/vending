arduino-cli compile --fqbn arduino:megaavr:nona4809 vending.ino &&
arduino-cli upload --port /dev/ttyACM0 --fqbn arduino:megaavr:nona4809 vending.ino