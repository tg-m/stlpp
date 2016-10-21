.DEFAULT_GOAL := all
TARGET := main.run

LIBCORENAME := stlpp
LIBNAME := lib$(LIBCORENAME)
LIBNAME_SO := $(LIBNAME).so

MAIN :=
TFILTER := \"\"
CFILTER :=

CXX := g++
CXXFLAGS := -std=c++11 -fpermissive -fPIC
CXXFLAGS += -O3
# CXXFLAGS += -g
# CXXFLAGS += -fprofile-arcs -ftest-coverage --coverage # code coverage


LDFLAGS :=
# LDFLAGS += -fprofile-arcs -ftest-coverage # code coverage

LIBS :=
# LIBS += -lgflags -lpthread -litpp -llapack -lboost_system -lboost_chrono -larmadillo # -l$(LIBNAME)
# LIBS += -lgcov # code coverage

#LIBS += `pkg-config --libs itpp`

SRC_DIR := stlpp
INSTALL_DIR := /usr/local/include


INC := $(addprefix -I, $(SRC_DIR))

SRC :=
SRC := $(shell find $(SRC_DIR) ! -name "*.test.cc" -name "*.cc")

IN_HH := $(shell find $(SRC_DIR) -name "*.in.hh")

COVERAGE_SRC := $(shell for f in $(SRC); do echo "$$f" | grep "$(CFILTER)"; done)
COVERAGE_RESULT_FILES := $(shell find . -name "*.gcda" -o -name "*.gcno" -o -name "*.gcov")


OBJ=$(patsubst %.cc,%.o,$(SRC))
MAIN_O=$(patsubst %.cc,%.o,$(MAIN))


all: generate_header_ # test_ # build_ package_ main_ link_


clean: clean_
build: build_
package: build_ package_
test: test_
install: install_
uninstall: uninstall_
generate_header: generate_header_

generate_header_:
	@echo "Generating header"
	@echo $(shell cat gen-comment.hh > $(SRC_DIR)/stlpp.gen.hh)
	@echo $(shell $(CXX) $(CXXFLAGS) -E  $(SRC_DIR)/stlpp.in.hh | sed 's/CAR_RET;/\n/g' | grep -v "^\#" >> $(SRC_DIR)/stlpp.gen.hh)


coverage:
	gcov -abcnr $(COVERAGE_SRC)

average_coverage:
	@echo $(shell gcov -abcnr $(COVERAGE_SRC) 2>/dev/null | grep Lines | sed 's/%//g' | sed 's/^.*://g' | awk 'BEGIN { sum=0.0; lines=0.0; } { lines=lines+'"$$"3'; sum=sum+'"$$"1'*'"$$"3';  } END { ave=sum/lines; print "Average line code cover of " NR " files with " lines " lines : " ave "%";}')

clean_:
	@echo "Cleaning..."
	-rm $(OBJ) 2> /dev/null || true
	-rm $(TARGET) 2> /dev/null || true
	-rm $(LIBNAME_SO) 2> /dev/null || true
	-rm $(COVERAGE_RESULT_FILES) 2>/dev/null || true
	make -f Tests.mk clean



build_: $(OBJ)
	@echo "Built modules"

package_:
	-rm $(LIBNAME_SO) > /dev/null || true
	$(CXX) -shared $(LDFLAGS) -o $(LIBNAME_SO) $(OBJ)
	chmod +x $(LIBNAME_SO)

main_: $(MAIN_O)
	@echo "Built $(MAIN)"

link_:
	@echo "Linking..."
	$(CXX) $(LDFLAGS) $(MAIN_O) -L./ -Wl,-rpath=./ -l$(LIBCORENAME) $(LIBS) -o $(TARGET)
	chmod +x $(TARGET)

%.o: %.cc
	$(CXX) -c $< $(CXXFLAGS) $(INC) -o $@

test_:
	make -f Tests.mk TESTED_CODE_PATH=./stlpp TESTING_CODE_PATH=./ MDM_LIB="$(LIBCORENAME)" TFILTER="$(TFILTER)" all test


install_:
	mkdir -p $(INSTALL_DIR)
	cp $(SRC_DIR)/stlpp.hh $(INSTALL_DIR)
	cp $(SRC_DIR)/stlpp.gen.hh $(INSTALL_DIR)

uninstall_:
	rm $(INSTALL_DIR)/stlpp.hh
	rm $(INSTALL_DIR)/stlpp.gen.hh

printInc:
	@echo $(INC)

printLdflags:
	@echo $(LDFLAGS

printLibs:
	@echo $(LIBS))

printCxxFlags:
	@echo $(CXXFLAGS)

printSrc:
	@echo $(SRC)

printInhh:
	@echo $(IN_HH)

printObj:
	@echo $(OBJ)

printMaino	:
	@echo $(MAIN_O)

printCfilter:
	@echo $(CFILTER)

printCoverageSrc:
	@echo $(COVERAGE_SRC)

printCoverageResultFiles:
	@echo $(COVERAGE_RESULT_FILES)

.PHONY : all clean build clean_ build_ link_ generate_header generate_header_
.PHONY : main_ package_ package uninstall uninstall_ install install_
.PHONY : test_ test
.PHONY : printInc printLdflags printCflags printSrc printCoverageResultFiles printCoverageSrc
.PHONY : coverage average_coverage
