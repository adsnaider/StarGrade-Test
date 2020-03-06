#/bin/sh

make bin/tests > /dev/null
./bin/tests --gradescope
