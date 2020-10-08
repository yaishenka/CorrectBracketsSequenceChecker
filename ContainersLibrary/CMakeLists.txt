set(LIBRARY ContainersLibrary)
add_library(ContainersLibrary STATIC "")


target_sources(${LIBRARY} PRIVATE
        Stack/Stack.cpp
        Utils/Utils.hpp
)