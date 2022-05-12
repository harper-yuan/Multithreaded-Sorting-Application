target = main
srcpp = main.cpp 
obj = $(srcpp:.cpp=.o)
$(target):$(obj)
	g++ -o $(target) $(obj) -g
$(obj):$(srcpp)
	g++ -c $(srcpp) -g

.PHONY: clean
clean:
	rm *.o