#!/bin/bash
echo "Enter your name:"
read name
echo "Hello, $name!"

if [ $# -eq 0 ]; then
  echo "No arguments supplied."
else
  echo "You entered $# arguments: $@"
fi

for arg in "$@"; do
  echo "Argument: $arg"
done

i=1
while [ $i -le 5 ]; do
  echo "Count: $i"
  ((i++))
done

case $1 in
  start) echo "Starting..." ;;
  stop) echo "Stopping..." ;;
  *) echo "Usage: $0 {start|stop}" ;;
esac
