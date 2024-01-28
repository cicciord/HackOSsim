# config
TEX_FILE_NAME := main
PDF_FILE_NAME := HackOSsim_Report
#


CURRENT_DIR := $(abspath .)

SRC_DIR 	:= $(CURRENT_DIR)/src
BUILD_DIR 	:= $(CURRENT_DIR)/build

ENTRY_POINT := $(TEX_FILE_NAME).tex
OUTPUT_FILE := $(TEX_FILE_NAME).pdf
OUTPUT_PDF 	:= $(PDF_FILE_NAME).pdf
SRC_FILES 	 = $(wildcard $(SRC_DIR)/*.tex)
SRC_FILES 	+= $(wildcard $(SRC_DIR)/**/*.tex)

default: $(BUILD_DIR)/$(OUTPUT_FILE)

$(BUILD_DIR)/$(OUTPUT_FILE): $(SRC_FILES) $(BUILD_DIR)
	cd $(SRC_DIR); \
		pdflatex \
			-halt-on-error \
			-shell-escape \
			-output-directory $(BUILD_DIR) \
			$(ENTRY_POINT) \
			2>&1 | tee $(BUILD_DIR)/errors.err
	cd $(SRC_DIR); \
		pdflatex \
			-halt-on-error \
			-shell-escape \
			-output-directory $(BUILD_DIR) \
			$(ENTRY_POINT) \
			2>&1 | tee $(BUILD_DIR)/errors.err

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

pdf: $(BUILD_DIR)/$(OUTPUT_FILE)
	cp $(BUILD_DIR)/$(OUTPUT_FILE) $(CURRENT_DIR)/../$(OUTPUT_PDF)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default clean pdf
