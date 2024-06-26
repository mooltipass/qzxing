// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef ZXING_ONED_READER_H
#define ZXING_ONED_READER_H

/*
 *  OneDReader.h
 *  ZXing
 *
 *  Copyright 2010 ZXing authors All rights reserved.
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
#include <zxing/DecodeHints.h>

namespace zxing {
namespace oned {

class OneDReader : public QZXingReader {
private:
  QSharedPointer<Result> doDecode(QSharedPointer<BinaryBitmap> image, DecodeHints hints);

protected:
  static const int INTEGER_MATH_SHIFT = 8;

  static int patternMatchVariance(std::vector<int>& counters,
                                  std::vector<int> const& pattern,
                                  int maxIndividualVariance);
  static int patternMatchVariance(std::vector<int>& counters,
                                  int const pattern[],
                                  int maxIndividualVariance);

protected:
  static const int PATTERN_MATCH_RESULT_SCALE_FACTOR = 1 << INTEGER_MATH_SHIFT;

public:
  struct Range {
  private:
    int data[2];
  public:
    Range() {}
    Range(int zero, int one) {
      data[0] = zero;
      data[1] = one;
    }
    int& operator [] (int index) {
      return data[index];
    }
    int const& operator [] (int index) const {
      return data[index];
    }
  };

  virtual QSharedPointer<Result> decode(QSharedPointer<BinaryBitmap> image, DecodeHints hints);

  // Implementations must not throw any exceptions. If a barcode is not found on this row,
  // a empty ref should be returned e.g. return QSharedPointer<Result>();
  virtual QSharedPointer<Result> decodeRow(int rowNumber, QSharedPointer<BitArray> row, DecodeHints hints) = 0;

  static void recordPattern(QSharedPointer<BitArray> row,
                            int start,
                            std::vector<int>& counters);

  static void recordPatternInReverse(QSharedPointer<BitArray> row,
                                     int start,
                                     std::vector<int>& counters);
  virtual ~OneDReader();
};

}
}

#endif // ZXING_ONED_READER_H

