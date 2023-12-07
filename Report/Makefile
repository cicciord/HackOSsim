SRC_DIR := ./src
BUILD_DIR := ./build

ENTRY_POINT := $(SRC_DIR)/main.tex
OUTPUT_FILE := $(BUILD_DIR)/main.pdf
SRC_FILES := $(wildcard $(SRC_DIR)/*.tex)

# build main.pdf as default
$(OUTPUT_FILE): $(SRC_FILES) $(BUILD_DIR)
	pdflatex -halt-on-error -shell-escape -output-directory $(BUILD_DIR) $(ENTRY_POINT) 2>&1 | tee $(BUILD_DIR)/errors.err
	pdflatex -halt-on-error -shell-escape -output-directory $(BUILD_DIR) $(ENTRY_POINT) 2>&1 | tee $(BUILD_DIR)/errors.err

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	@rm -rf build

.PHONY: default clean
