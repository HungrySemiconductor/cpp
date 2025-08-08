CXX = g++		# 编译器名称
TARGET = mul	# 可执行文件名称
SRC = $(wildcard *.cpp)					# .cpp文件	
OBJ = $(patsubst %.cpp, %.o, $(SRC))	# .o文件，由.cpp文件编译而来的

CXXFLAGS = -c -Wall		# 编译选项，显示所有警告

$(TARGET): $(OBJ)		# 目标文件链接成可执行文件
	$(CXX) -o $@ $^

%.o: %.cpp				# 每个.cpp文件转换为对应的.o文件
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean	# 防止存在clean重名文件
clean:
	rm -f *.o $(TARGET)

