# binaries
TARGET		:= bin/test_packet

# source
SOURCES		:= src/main.c

# tests
TSTSOURCES	:= tests/test.c

# dirs
CREATEDIRS	:= doc

# list of derived file names from the source names
OBJECTS		:= $(SOURCES:%.c=%.o)
DEPS		:= $(SOURCES:%.c=%.d)
TSTOBJECTS	:= $(TSTSOURCES:%.c=%.o)
TSTDEPS		:= $(TSTSOURCES:%.c=%.d)
TSTTARGET	:= $(CURDIR)/tests/runtest

# libs
CUNITINCDIR	:= $(CURDIR)/../CUnit/include
CUNITLIBDIR	:= $(CURDIR)/../CUnit/lib
TSTINCDIR	:= $(CURDIR)/../include
TSTLIBDIR	:= $(CURDIR)/../lib

# full path
FULLTARGET	:= $(CURDIR)/$(TARGET)

# commands
CC		= gcc
CFLAGS		= -std=c99 -Wall -g
LDFLAGS		= -static -z muldefs

# always visit
.PHONY: default clean test doc mkdir

#targets

default: $(FULLTARGET)
	@echo "#### $< built ####"

$(FULLTARGET): mkdir $(OBJECTS) Makefile
	$(LINK.c) -o $@ $(OBJECTS) -lm

clean:
	$(RM) $(TARGET) $(OBJECTS) $(DEPS) $(TSTTARGET) $(TSTOBJECTS) $(TSTDEPS) $(wildcard */*~ *~ tests/*.txt)
	$(RM) -r $(CREATEDIRS)
	@echo "#### $@ done ####"

doc:
	doxygen ../Doxyfile > /dev/null
	@echo "#### $@ done ####"

test:	$(TSTTARGET)
	(cd tests; $(TSTTARGET))
	@echo "#### $< executed ####"

$(TSTTARGET): $(FULLTARGET) $(TSTOBJECTS)
	 $(LINK.c) -o $(TSTTARGET) $(TSTOBJECTS) $(OBJECTS) -L$(CUNITLIBDIR) -lcuni    t -L$(TSTLIBDIR) -lprogctest
	@echo "#### $@ built ####" 

# create dirs
mkdir:
	-mkdir -p $(CREATEDIRS)

# read deps
-include $(DEPS) $(TSTDEPS)