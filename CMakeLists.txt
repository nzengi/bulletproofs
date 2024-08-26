cmake_minimum_required(VERSION 3.10)
project(Bulletproofs)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(bulletproofs ${SOURCES})

# Link secp256k1 library
find_library(SECP256K1_LIB secp256k1 REQUIRED)
target_link_libraries(bulletproofs ${SECP256K1_LIB})
