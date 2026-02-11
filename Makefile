SUBDIRS := stack doubly_linked_list dynamic_array hash_table heap

all:
	for d in $(SUBDIRS); do $(MAKE) -C $$d; done
	@echo "Built all data structures."

clean:
	for d in $(SUBDIRS); do $(MAKE) -C $$d clean; done
	@echo "Cleaned all data structures."

.PHONY: all clean
