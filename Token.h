#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <ostream>
#include <string>

namespace ds {

class Token {
public:
  enum class Kind {
    Number,
    Variable,
    LeftParen,
    RightParen,
    Equal,
    Plus,
    Minus,
    Asterisk,
    Semicolon,
    End,
    Unexpected
  };

  Kind kind{};
  std::string lexeme{};

  explicit Token(Kind k) : kind(k) {}

  Token(Kind k, const std::string &s) : kind(k), lexeme(s) {}

  Token(Kind k, std::string::const_iterator beg, size_t len)
      : kind(k), lexeme(beg, beg + len) {}

  Token(Kind k, std::string::const_iterator beg,
        std::string::const_iterator end)
      : kind(k), lexeme(beg, end) {}

  friend std::ostream &operator<<(std::ostream &os, const Token &token) {
    static const char *const names[]{
        "Number", "Variable", "LeftParen", "RightParen", "Equal",     "Plus",
        "Minus",  "Asterisk", "Semicolon", "End",        "Unexpected"};
    return os << names[static_cast<int>(token.kind)] << "("
              << token.lexeme + ")";
  }
  
  //helper functions to check the kind of a token
  bool is(Kind k) const { return kind == k; }

  bool is_one_of(Kind k1, Kind k2) const { return is(k1) || is(k2); }

  template <typename... Ts> bool is_one_of(Kind k1, Kind k2, Ts... ks) const {
    return is(k1) || is_one_of(k2, ks...);
  }
};

} // namespace ds

#endif // __TOKEN_H__