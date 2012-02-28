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

#include "gdcmReader.h"
#include "gdcmAttribute.h"

int main( int argc, char* argv[] )
{

  if( argc < 2 )
    {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " InputDicomImage " << std::endl;
    return EXIT_FAILURE;
    }

  gdcm::Reader reader;

  reader.SetFileName( argv[1] );
  reader.Read();

  const gdcm::File & file = reader.GetFile();

  const gdcm::DataSet & dataset = file.GetDataSet();

  gdcm::Attribute<0x5600,0x0020> at;
  at.Set( dataset );

  std::cout << "VALUE = " << at.GetValue() << std::endl;


  return EXIT_SUCCESS;

}
