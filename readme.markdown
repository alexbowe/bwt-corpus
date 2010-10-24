Burrows-Wheeler Transforms
==========================

The original and generated data is available on S3
[here](http://bwt-corpus.s3.amazonaws.com/list.html).
This repository is simply to allow people to reproduce the data themselves.

Do-It-Yourself
--------------

To build, run `build_data.sh` (after compiling the included programs).
You must have the original Pizza&Chili data in the project directory.

Description
-----------

The purpose of this is to provide a way of reproducing the data I am using in
my thesis. The original data is taken from the 
[Pizza&Chili](http://pizzachili.dcc.uchile.cl/texts.html) corpus.

The files used are english, proteins, dna, sources, xml of 50MB, 100MB and 200MB
sizes. I have also created 25MB and 75MB versions of these.

Process
-------

Here is the process used to get the BWTs:

 * *swit* is used for mapping words to ints, and is written by Christopher Hoobin from RMIT.
 * [qsufsort](http://www.larsson.dogma.net/research.html) for creating a Suffix
 Array from int arrays (as produced by swit). I provide a harness
 program `intbwt` which gets the BWT from the resulting suffix array.
 * [libdivsufsort](http://code.google.com/p/libdivsufsort/) is used for creating
 BWTs from character arrays.
 
During this, I remove the End-Of-String symbol (or pointer) in the BWTs, as it
is of no use to me in a Wavelet Tree, and wouldn't need to be stored in anywhere
but the host Suffix Array.
