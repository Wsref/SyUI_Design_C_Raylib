CC = gcc
INCDIR = -Iinclude
LIBDIR = -Llib -L"/c/msys64/mingw64/x86_64-w64-mingw32/lib" -L"/c/msys64/mingw64/lib"
CFLAGS += -O2 -Wall -std=c99
LDFLAGS +=-ltmx -lxml2 -lz -lraylib -lopengl32 -lgdi32  -lws2_32 -llzma -liconv -lwinmm

.PHONY: all clean

all:
	$(CC) src/stMang.c src/mapAuHll.c src/getData.c src/loadTextur.c src/emploDesi.c src/emploData.c src/Scrolling.c  src/searchMaintenance.c -o  taoufik.exe $(CFLAGS) $(INCDIR) $(LIBDIR) $(LDFLAGS)