
CC=mipsel-linux-gcc
#CC=gcc 
 

SRCS= TAS3xxxDownload.c DSP.c I2C.c UserMath.c DataStg.c TAS3xxx.c    
OBJS=$(patsubst %.c,%.o,$(SRCS) ) 

%.o:%.c 
	$(CC) -fPIC -c  $< -o $@  -std=c99

.PHONY:all clean
all:lrsunDsp.so

lrsunDsp.so:$(OBJS)
	$(CC) -shared -fPIC -o lrsunDsp.so $(OBJS) -lm -std=c99
	
#all:test
#test:$(OBJS)
#	$(CC) -fPIC -o test $(OBJS) -lm -std=c99
	
clean:
	rm *.o *.so -rf


      



