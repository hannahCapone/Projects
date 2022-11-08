#ifndef __TRANSFORMER_H__
#define __TRANSFORMER_H__

#include "Tokenizer.h"
#include <stack>

using namespace std;

namespace ds {

class InfixToPostfixTransformer {
public:
  /**
   * Helper method to do the transformation.
   */
  static stack<Token> transform(const string &code) {
    VList<Token> infix = tokenStreamToList(code);
    return infixToPostfix(infix);
  }

private:
  /**
   * Convert stream of tokens to a list.
   */
  static VList<Token> tokenStreamToList(const string &code) {
    Tokenizer lexer(code);
    VList<Token> res;
    for (Token token = lexer.next();
         !token.is_one_of(Token::Kind::End, Token::Kind::Unexpected);
         token = lexer.next())
      res.addLast(token);
    return res;
  }

  static stack<Token> infixToPostfix(const VList<Token> &infix);
};

} // namespace ds

#endif // __TRANSFORMER_H__