.PHONY: clean All

All:
	@echo "----------Building project:[ Exercise_06 - Debug ]----------"
	@cd "Exercise_06" && "$(MAKE)" -f  "Exercise_06.mk"
clean:
	@echo "----------Cleaning project:[ Exercise_06 - Debug ]----------"
	@cd "Exercise_06" && "$(MAKE)" -f  "Exercise_06.mk" clean
