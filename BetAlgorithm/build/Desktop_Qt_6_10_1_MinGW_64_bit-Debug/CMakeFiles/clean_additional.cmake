# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BetAlgorithm_autogen"
  "CMakeFiles\\BetAlgorithm_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BetAlgorithm_autogen.dir\\ParseCache.txt"
  )
endif()
