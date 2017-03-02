#ifndef READXL_STRINGSET_
#define READXL_STRINGSET_

#include <Rcpp.h>

class StringSet
{
  std::set<std::string> set_;
public:
  StringSet(const char *s = "") {
    if (strlen(s) > 0)
      set_.insert(s);
  }
  template <size_t SIZE>
  StringSet(const std::string (&s)[SIZE]) {
    for (size_t i = 0; i < SIZE; ++i) {
      set_.insert(s[i]);
    }
  }
  StringSet(const std::vector<std::string> &s) {
    for (std::vector<std::string>::const_iterator i = s.begin(); i != s.end(); ++i)
      set_.insert(*i);
  }
  StringSet(const Rcpp::CharacterVector &s) {
    for (Rcpp::CharacterVector::const_iterator i = s.begin(); i != s.end(); ++i)
      set_.insert(Rcpp::as<std::string>(*i));
  }
  bool contains(const std::string &s) const {
    return set_.find(s) != set_.end();
  }
  bool contains(const double d) const {
    std::ostringstream str; str << d;
    return contains(str.str());
  }
};

#endif
