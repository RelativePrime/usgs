== Environment ==

BAMS_Predict.config file defines the input, output and other variables.


== Compiling and Linking ==

You can import this code base as an Eclipse project and build.

Libraries required for linking:
hdf hdf-devel hdfeos opencv opencv-devel libnetcdf4 libproj0 netcdf proj sz gdal Gctp


== To do ==

Add a GNU makefile 

Troubleshoot gbtrees.predict function in the predict.cpp which should return 0 or 1, but is returning non bool values.

Add some hdf (and header) files for testing. lndsr.LT50270342005077PAC01.hdf was being used for testing previously.


