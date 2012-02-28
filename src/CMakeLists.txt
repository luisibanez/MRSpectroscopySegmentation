#
#  Source code for evaluation metrics
#

add_executable(MRSpectroscopyReader
  DicomImageReadWrite.cxx
  )

target_link_libraries(MRSpectroscopyReader ${ITK_LIBRARIES})
