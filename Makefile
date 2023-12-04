SRC_DIR := ./src
BUILD_DIR := ./build

# build main.pdf as default
.PHONY: default
default: $(BUILD_DIR)/main.pdf

# build <filename>.pdf from <filename>.tex
# it builds it twice (solve some references issue)
$(BUILD_DIR)/%.pdf: $(SRC_DIR)/%.tex
	pdflatex -halt-on-error -output-directory $(BUILD_DIR) $< 2>&1 | tee errors.err
	$(MAKE) $@

.PHONY: clean
clean:
	rm errors.err
	rm $(BUILD_DIR)/*.aux
	rm $(BUILD_DIR)/*.log
	rm $(BUILD_DIR)/*.out
	rm $(BUILD_DIR)/*.pdf
	rm $(BUILD_DIR)/*.toc
