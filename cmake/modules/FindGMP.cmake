# Locate the gmp library and its includes
find_path(GMP_INCLUDE_DIR NAMES gmp.h)
find_library(GMP_LIBRARY gmp)
find_library(GMP_LIBRARY gmpxx)
if(GMP_LIBRARY MATCHES ${CMAKE_SHARED_LIBRARY_SUFFIX})
  set(gmp_library_type SHARED)
else()
  set(gmp_library_type STATIC)
endif()

message(STATUS "GMP: ${GMP_LIBRARY}, ${GMP_INCLUDE_DIR}")

add_library(gmp ${gmp_library_type} IMPORTED)
add_library(gmpxx ${gmp_library_type} IMPORTED)

set_target_properties(
  gmp PROPERTIES
  IMPORTED_LOCATION ${GMP_LIBRARY}
  INTERFACE_INCLUDE_DIRECTORIES ${GMP_INCLUDE_DIR}
)

set_target_properties(
  gmpxx PROPERTIES
  IMPORTED_LOCATION ${GMP_LIBRARY}
  INTERFACE_INCLUDE_DIRECTORIES ${GMP_INCLUDE_DIR}
)