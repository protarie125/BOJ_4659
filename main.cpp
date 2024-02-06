#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

string s;

bool IsV(char c) {
  return ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c);
}

bool HasV() {
  for (const auto& c : s) {
    if (IsV(c)) {
      return true;
    }
  }

  return false;
}

bool ConnThree() {
  auto conn = 0;
  auto bf = -1;
  for (const auto& c : s) {
    if (-1 == bf) {
      if (IsV(c)) {
        bf = 0;
      } else {

        bf = 1;
      }
      conn = 1;
      continue;
    }

    if (0 == bf) {
      if (IsV(c)) {
        ++conn;
        if (3 == conn) {
          return true;
        }
      } else {
        bf = 1;
        conn = 1;
      }
      continue;
    }

    if (1 == bf) {
      if (IsV(c)) {
        bf = 0;
        conn = 1;
      } else {
        ++conn;
        if (3 == conn) {
          return true;
        }
      }
    }
  }

  return false;
}

bool Double() {
  auto bf = char{0};
  for (const auto& c : s) {
    if ('e' == c || 'o' == c) {
      bf = 0;
      continue;
    }

    if (bf == c) {
      return true;
    }

    bf = c;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> s;
  while ("end" != s) {
    auto is_acceptable = bool{true};

    if (!HasV()) {
      is_acceptable = false;
    }

    if (ConnThree()) {
      is_acceptable = false;
    }

    if (Double()) {
      is_acceptable = false;
    }

    if (is_acceptable) {
      cout << "<" << s << "> is acceptable.\n";
    } else {
      cout << "<" << s << "> is not acceptable.\n";
    }

    cin >> s;
  }

  return 0;
}