#! /usr/bin/python

import sys

def usage():
    sys.stderr.write("Usage: strip_bytes <numbytes> "
        + "<input file> <output file>\n")
        
def stripBytes(num_bytes, in_file, out_file):
    f = open(in_file, 'rb')
    f.seek(num_bytes)
    data = f.read()
    f.close()

    f = open(out_file, 'wb')
    f.write(data)
    f.close()

if __name__ == '__main__':
    if len(sys.argv) is not 4:
        usage()
        exit()
    try:
        num_bytes = int(sys.argv[1])
        in_file = sys.argv[2]
        out_file = sys.argv[3]
    
        stripBytes(num_bytes, in_file, out_file)
    except:
        usage()
