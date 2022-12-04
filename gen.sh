#!/bin/bash

set -e

for i in {000..050}
do
	echo Generating... $i
	./gen
	file="out/lines$i.png"
	echo Converting... $file
	ffmpeg -i image.ppm $file -hide_banner -loglevel error -y
done

#FILES=$(find out/ -name lines*.png -ls | sort -k11 | awk '{split($0,a," "); print a[11]}')

ffmpeg -f image2 -i out/lines%003d.png video.mkv -hide_banner -loglevel error -y
