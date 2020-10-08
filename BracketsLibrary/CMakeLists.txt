set(LIBRARY BracketsLibrary)
add_library(BracketsLibrary STATIC "")


target_sources(${LIBRARY} PRIVATE
        Bracket.cpp
        BracketParser.cpp
        BracketsSequence.cpp
)