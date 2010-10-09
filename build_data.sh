#! /bin/bash

SWIT=tools/swit/bin/translate
CHAR_BWT=tools/libdivsufsort-2.0.0/examples/bwt
STRIP=tools/strip_bytes.py
INT_BWT=tools/intbwt/intbwt

# Create ASCII BWT files
for file in ./*.*MB
do
    echo Creating BWT for $file...
    $CHAR_BWT $file $file.bwt
    echo Stripping EOS pointer from start...
    $STRIP 8 $file.bwt $file.bwt
done

# Int-map English files
# and create BWT
for file in ./english.*MB
do
    echo Int-mapping $file...
    $SWIT $file
    echo Creating BWT for $file.swit...
    $INT_BWT $file.swit
done

echo Moving to BWT folder...
mkdir bwt
mv *.bwt bwt
