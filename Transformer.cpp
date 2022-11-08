#include "Transformer.h"

namespace ds {
// helper function for precedence
// 1: a > b, 2 a = b, 3: a <b
// * +/- =
bool precOrSame(Token a ,Token b)
{ 
  // return true if a >= b
  if (a.kind == b.kind)
  {
    return true;
  }
  // a is different than b
  else if (a.is(Token::Kind::Asterisk)) 
  {
    return true;
  }
  else if (b.is(Token::Kind::Asterisk))
  {
    return false;
  }
  else if (a.is(Token::Kind::Equal))
  {
    return false;
  }
  else if (b.is(Token::Kind::Equal))
  {
    return true;
  }
  // a and b could be either + or - 
  return true; // same precendece
}
/**
 * Transform the token stream from infix to postfix form.
 *
 * @param infix list of tokens in infix notation
 * @return stack<Token> token stack in postfix notation
 */
stack<Token>
InfixToPostfixTransformer::infixToPostfix(const VList<Token> &infix) {
  // Example:
  // https://docs.google.com/presentation/d/1NO2ZKEVu3IZ07Oy-QNxdAell_FThC6RylEWDEGRim6U/edit#slide=id.gecc4e479c6_0_11
  // TODO:
  // create postfix stack
  stack<Token> postfixStk;
  
  // create opStk for operators
  stack<Token> opStk;

  // for loop
  for (int i = 0; i < infix.size(); i++)
  {
    // iterate through the infix token list
    Token tk = infix.get(i); // the i-th token

    // if tk is a number or a variable:
    if (tk.is_one_of(Token::Kind::Number, Token::Kind::Variable))
    {
      postfixStk.push(tk);
    }

    // if tk is a plus, minus, equal, or asterisk:
    else if (tk.is_one_of(Token::Kind::Plus, Token::Kind::Minus, Token::Kind::Equal, Token::Kind::Asterisk))
    {
      while (!(opStk.empty()) && !(opStk.top().is(Token::Kind::LeftParen)) &&
             precOrSame(opStk.top(), tk))
      {
        // transfer tokens from opStk to postfixStk
        postfixStk.push(opStk.top());
        opStk.pop();
      }
      // push tk to opStk
      opStk.push(tk);
    }

    // if tk is a '(' leftparen:
    else if (tk.is(Token::Kind::LeftParen))
    {
      opStk.push(tk);
    }

    // if tk is a ')' rightparen:
    else if (tk.is(Token::Kind::RightParen))
    {
      while (!opStk.empty())
      {
        // if left paren break
        if (opStk.top().is(Token::Kind::LeftParen))
        {
          opStk.pop();
          break;
        }
        else 
        {
          // transfer tokens from opStk to postfixStk
          postfixStk.push(opStk.top());
          opStk.pop();
        }
      }
    }
    
    else if(tk.is(Token::Kind::Semicolon))
    {
      while (!opStk.empty())
      {
        // transfer tokens from opStk to postfixStk
        postfixStk.push(opStk.top());
        opStk.pop();
      }
      // push semicolon
      postfixStk.push(tk);
    }
  }
  // transfer tokens from opStk to postfixStk
  while (!opStk.empty())
  {
    postfixStk.push(opStk.top());
    opStk.pop();
  }

  // final return
  return postfixStk;
}

} // namespace ds
