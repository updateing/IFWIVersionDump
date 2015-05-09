objs = main.o fw_version_check.o check_perform.o

EXECUTABLE_NAME := ifwi_ver_dump
CFLAGS := -Wall

ifwi_ver_dump : $(objs)
	$(CC) $(CFLAGS) -o $(EXECUTABLE_NAME) $(objs)

$(objs) : fw_version_check.h
main.o : check_perform.h

.PHONY : clean
clean :
	rm -f $(EXECUTABLE_NAME) $(objs)
