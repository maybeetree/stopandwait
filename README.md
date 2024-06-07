# Stop-and-Wait protocol simulation

This is a C++98 program to simulate the stop-and-wait protocol.

## Building

G++ and Make are needed to compile this program.

```
make
```

## Using

The program takes two command-line arguments: `p_1` and `p_2`,
where `p_1` is the probability of a data packet from
sender to receiver getting corrupted,
and `p_2` is the probability of an ACK packet
from receiver to sender getting corrupted.
Probability is a float between 0 and 1.
The program then reads the data to be transmitted from stdin,
as a bunch of numbers separated by whitespace (newline, space or tab)
until EOF.

The output is a bunch of lines,
where each line represents the receiver's buffer
at each timestep as tab-separated decimal numbers.
The buffer fills up from left to right
untill all data is received.
The buffer is not initialized,
so until all data is received,
it may contain zeroes or garbage
depending on the platform.

```
 $ echo '4 8 15 16 23 42' | ./snw 0.1 0.8
4       0       0       0       0       0
4       0       0       0       0       0
4       0       0       0       0       0
4       0       0       0       0       0
4       0       0       0       0       0
4       0       0       0       0       0
4       8       0       0       0       0
4       8       0       0       0       0
4       8       0       0       0       0
4       8       0       0       0       0
4       8       0       0       0       0
4       8       15      0       0       0
4       8       15      16      0       0
4       8       15      16      23      0
4       8       15      16      23      0
4       8       15      16      23      42
4       8       15      16      23      42
4       8       15      16      23      42
4       8       15      16      23      42
4       8       15      16      23      42
```

## Experiments

Experiments can be run by executing the shell script `experiments.sh`,
after the main `snw` program has been compiled.
The experiment results are written to the `dat` directory.

The `experiments.sh`
script has been tested with GNU Coreutils and dash.
Other shells and coreutils implementations are
not guaranteed to work,
but probably will.

## Compiling the report

Typst is required to compile the report.
While compiling, there must be an internet connection,
so that typst can download the required `plotst` package.
The report reads experiment data from `/dat`,
therefore it is necessary to run the experiments before
compiling the report.

Once these requirements are satisfied,
the report can be compiled using the typst command line tool:

```
typst compile report.typ 
```

## License

You should have received a copy of the CC0 Public Domain Dedication
along with this software.
If not, see http://creativecommons.org/publicdomain/zero/1.0/.

