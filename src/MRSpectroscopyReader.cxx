/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "gdcmImage.h"
#include "gdcmImageReader.h"
#include "gdcmAttribute.h"

int main( int argc, char* argv[] )
{

  if( argc < 2 )
    {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " InputDicomImage " << std::endl;
    return EXIT_FAILURE;
    }

  gdcm::ImageReader reader;

  reader.SetFileName( argv[1] );
  reader.Read();

  const gdcm::File & file = reader.GetFile();

  const gdcm::DataSet & dataset = file.GetDataSet();

  gdcm::Attribute<0x0008,0x0016> at;
  at.Set( dataset );

  std::string SOPClassUID = at.GetValue();
  std::string SOPClassUIDMRS = "1.2.840.10008.5.1.4.1.1.4";

  std::cout << "SOPClassUID = " << SOPClassUID << std::endl;

  if( SOPClassUID.compare(0,25,SOPClassUIDMRS) != 0 )
    {
    std::cerr << "The input file does not seem to be MR Spectroscpy data" << std::endl;
    std::cerr << "Expected : " << SOPClassUIDMRS << " length = " << SOPClassUIDMRS.length() << std::endl;
    std::cerr << "Found    : " << SOPClassUID    << " length = " << SOPClassUID.length()    << std::endl;
    return EXIT_FAILURE;
    }

  const gdcm::Image & image = reader.GetImage();

  const unsigned int * imageSize = image.GetDimensions();

  std::cout << "Dimensions = " << imageSize[0] << " x " << imageSize[1] << std::endl;

  const gdcm::PixelFormat & pixelFormat = image.GetPixelFormat();

  pixelFormat.Print( std::cout );


  return EXIT_SUCCESS;

}
