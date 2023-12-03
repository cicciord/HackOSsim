# build main.pdf as default
.PHONY: default
default: main.pdf

# build <filename>.pdf from <filename>.tex
# it builds it twice (solve some references issue)
%.pdf: %.tex
	pdflatex $< -o $@ 2>&1 | tee errors.err
	$(MAKE) $@


.PHONY: clean
clean:
	rm errors.err
	rm *.aux
	rm *.log
	rm *.out
	rm *.pdf
