# 编译器设置
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

# 目标可执行文件
TARGET := factory_test

# 源文件和对象文件
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
DEPS := $(patsubst %.cpp,%.d,$(SRCS))  # 依赖文件

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译规则（含自动依赖生成）
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# 清理（跨平台兼容写法）
clean:
ifeq ($(OS),Windows_NT)
	del /Q /F $(TARGET).exe $(OBJS) $(DEPS) 2>nul
else
	rm -f $(TARGET) $(OBJS) $(DEPS)
endif

# 包含自动生成的依赖
-include $(DEPS)

.PHONY: all clean