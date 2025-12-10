OUTDIR = out

all: $(OUTDIR)/test-lab

$(OUTDIR)/test-lab: main.cpp
	mkdir -p $(OUTDIR)
	g++ -std=c++17 -Wall main.cpp -o $(OUTDIR)/test-lab

test: $(OUTDIR)/test-lab
	$(OUTDIR)/test-lab
