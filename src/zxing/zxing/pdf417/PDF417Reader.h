// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef ZXING_PDF417_READER_H
#define ZXING_PDF417_READER_H

/*
 *  PDF417Reader.h
 *  zxing
 *
 *  Copyright 2010,2012 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <zxing/QZXingReader.h>
#include <zxing/pdf417/decoder/Decoder.h>
#include <zxing/DecodeHints.h>

namespace zxing {
namespace pdf417 {


class PDF417Reader : public QZXingReader {
 private:
  decoder::Decoder decoder;
			
  static QSharedPointer<BitMatrix> extractPureBits(QSharedPointer<BitMatrix> image);
  static int moduleSize(QSharedPointer<std::vector<int>> leftTopBlack, QSharedPointer<BitMatrix> image);
  static int findPatternStart(int x, int y, QSharedPointer<BitMatrix> image);
  static int findPatternEnd(int x, int y, QSharedPointer<BitMatrix> image);

 public:
  QSharedPointer<Result> decode(QSharedPointer<BinaryBitmap> image, DecodeHints hints);
  void reset();
};

}
}

#endif // ZXING_PDF417_READER_H
