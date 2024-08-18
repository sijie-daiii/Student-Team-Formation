IDIR = .
CC = g++
CFLAGS = -I$(IDIR) -g -std=c++11 -O0

ODIR = .
SDIR = .

_DEPS = student_data/student_data.hpp team_operations/team_operations.hpp skill_level/skill_level.hpp csv_operations/csv_operations.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = team_operations/team_operations.o main.o csv_operations/csv_operations.o skill_level/skill_level.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ core $(IDIR)/*~
	rm -f main
	find . -name "*.o" -type f -delete
