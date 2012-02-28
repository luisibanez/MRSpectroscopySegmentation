#
#  Source code for evaluation metrics
#

add_executable(MRSpectroscopyReader DicomImageReadWrite.cxx)
target_link_libraries(MRSpectroscopyReader ${ITK_LIBRARIES})

add_executable(DicomImageReadPrintTags DicomImageReadPrintTags.cxx)
target_link_libraries(DicomImageReadPrintTags ${ITK_LIBRARIES})
