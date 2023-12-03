filename=main

pdf-firefox: pdf
	firefox $(filename).pdf

pdf: $(filename).tex
	pdflatex $(filename).tex

clean:
	rm $(filename).{aux,log,out,pdf}
