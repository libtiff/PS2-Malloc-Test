# All lines beginning with a hash/pound/number sign are comments, these are ignored by the computer.
 
# This line specifies the final output binary, this is what the PS2 will execute.
EE_BIN = malloc.elf
 
# This line specifies the object files, these are an intermediate step in the creation of the final program.
EE_OBJS = malloc.o
 
# This line specifies the libraries required for this program to work.
# Specifically in this case it's the libdebug library. This allows us to print text to the debug console.
EE_LIBS = -ldebug
 
# This is the first and default "target", it specifies information for the default buildchain output.
all: $(EE_BIN)
 
# This specifies how to "clean" the project, it deletes all the old files from previous builds, but not the code you've written.
clean:
	rm -f *.elf *.o *.a
 
# These are includes, they specify stuff for multiple makefiles, you can add these lines to any makefile which requires them, they're not project-specific.
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
