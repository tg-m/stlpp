.DEFAULT_GOAL = all

TFILTER := ""


CPP := g++
CXXFLAGS := -c -std=c++0x -fPIC
# CXXFLAGS += -fprofile-arcs -ftest-coverage --coverage # code coverage
#CXXFLAGS += -O3
#CXXFLAGS += -g

#CXXFLAGS := -fsanitize=address

LDFLAGS :=
LDFLAGS += -lgtest -pthread
#LDFLAGS += -lboost_thread -lboost_system -lboost_chrono
# LDFLAGS += -fprofile-arcs -ftest-coverage # code coverage

TESTED_CODE_PATH := ./stlpp
TESTING_CODE_PATH := ./

TESTING_CODE_PATTERN := "*.test.cc"


INC :=
INC += $(addprefix -I, $(TESTED_CODE_PATH))




TEST_SCRIPT := test.sh.run

#ifneq ($(TFILTER),"")
SRC := $(shell find $(TESTING_CODE_PATH) -name $(TESTING_CODE_PATTERN) | grep "$(TFILTER)")
#else
	#SRC := $(shell find $(TESTING_CODE_PATH) -name $(TESTING_CODE_PATTERN))
#endif

OBJ := $(SRC:.cc=.o)
RUN := $(SRC:.cc=.run)


$(OBJ): %.o: %.cc
	$(CPP) $< $(CXXFLAGS) $(INC) -o $@

$(RUN): %.run: %.o
	$(CPP) $< $(LDFLAGS) -o $@
	

build: $(OBJ)

link: $(RUN)

test: prepareTest runTests

prepareTest: prepareTestScript writeTestScript

runTests:
	@./$(TEST_SCRIPT)


prepareTestScript:
	@-rm ./$(TEST_SCRIPT) 2> /dev/null || true
	@touch ./$(TEST_SCRIPT)
	@echo \#!/bin/bash > ./$(TEST_SCRIPT)
	@echo "" >> ./$(TEST_SCRIPT);
	@echo MSG=\"\" >> ./$(TEST_SCRIPT);
	@chmod +x $(TEST_SCRIPT)


dollar="$$"
writeTestScript: $(RUN)
	@for X in $(RUN); do \
		echo "" >> $(TEST_SCRIPT); \
		echo "echo Running: $$X" >> $(TEST_SCRIPT); \
		echo ./$$X >> $(TEST_SCRIPT); \
		echo "RET=$(dollar)?;" >> $(TEST_SCRIPT); \
		echo "if [ $(dollar)RET != 0 ]; then" >> $(TEST_SCRIPT); \
		echo "    MSG=$(dollar)MSG\"" >> $(TEST_SCRIPT); \
		echo "    $(dollar)(basename $$X)\tfailed and returned:\t \"$(dollar)RET;" >> $(TEST_SCRIPT); \
		echo "fi" >> $(TEST_SCRIPT); \
		echo "" >> $(TEST_SCRIPT); \
	done
	@echo "" >> ./$(TEST_SCRIPT);
	@echo "echo \"$(dollar)MSG\";" >> ./$(TEST_SCRIPT);


testWithDisabledTests: prepareTestScriptWithDisabledTests runTests

prepareTestScriptWithDisabledTests: prepareTestScript writeTestScriptWithDisabledTests

writeTestScriptWithDisabledTests: $(RUN)
	@for X in $(RUN); do \
		echo "" >> $(TEST_SCRIPT); \
		echo "echo Running: $$X --gtest_also_run_disabled_tests" >> $(TEST_SCRIPT); \
		echo ./$$X --gtest_also_run_disabled_tests >> $(TEST_SCRIPT); \
	done


setup:
	chmod +x $(RUN)


all: clean build link setup

%.o: %.cc
	@echo "$< -> $@"
	$(CPP) -c $< $(CXXFLAGS) $(INC) -o $@


# removing with ignoring if no such files
clean:
	@echo "Cleanning up..."
	-@rm $(OBJ) 2> /dev/null || true
	-@rm $(RUN) 2> /dev/null || true
	-@rm ./$(TEST_SCRIPT) 2> /dev/null || true
	-@rm ./*.test.log 2> /dev/null || true




printInc:
	@echo $(INC)
	
printSrc:
	@echo $(SRC)

.PHONY: all clean printInc build setup test run runTest prepareTest prepareTestScript
.PHONY: testWithDisabledTests
