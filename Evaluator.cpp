#include "Evaluator.h"

namespace ds {

/**
 * Create an expression tree from a stack of tokens in postifx form
 *
 * @param tokenStk the postfix tokens; may contain variables, numbers, plus,
 * minus, equal, and semicolon
 * @return ExprTreeNode* the root of the generated expression tree
 */
ExprTreeNode *Evaluator::buildExprTree(std::stack<Token> &tokenStk) {

  if (tokenStk.empty())
  {
    return nullptr;
  }
  else 
  {
    while (!tokenStk.empty())
    {
      Token t = tokenStk.top();
      if (t.is_one_of(Token::Kind::Variable, Token::Kind::Number)) {
        // consume t
        ExprTreeNode *n = new ExprTreeNode(t);
        // pop t from stack
        tokenStk.pop();
        // return the node n
        return n;
        //delete n;
      } else if (t.is_one_of(Token::Kind::Plus, Token::Kind::Minus,
                             Token::Kind::Equal, Token::Kind::Semicolon, Token::Kind::Asterisk)) {
        // consume t
        ExprTreeNode *n = new ExprTreeNode(t);
        // pop t from stack
        tokenStk.pop();
        // build expression tree for expr2 & expr1 recursively
        n->expr2 = buildExprTree(tokenStk);
        n->expr1 = buildExprTree(tokenStk);
        // return node n
        return n;
        //delete n;
      }
    }
  }
  
  return nullptr;
}

/**
 * Evaluate the given expression tree
 *
 * @param root the root of the expression tree
 * @param varTbl the map from a variable to its value
 * @return BigInt the result of the expression; if the tree is empty, simply
 * return an empty BigInt
 */
BigInt Evaluator::evaluateExprTree(const ExprTreeNode *root,
                                   std::map<std::string, BigInt> &varTbl) {

  if (root == nullptr) 
  {
    return BigInt();
  } 
  else if (root->token.is(Token::Kind::Number)) 
  {
    BigInt returnVal = BigInt(root->token.lexeme);
    return returnVal;
  }
  else if (root->token.is(Token::Kind::Variable))
  {
    return varTbl[root->token.lexeme];
  } 
  else if (root->token.is(Token::Kind::Semicolon)) 
  {
    evaluateExprTree(root->expr1, varTbl);
    return evaluateExprTree(root->expr2, varTbl);
  } 
  else if (root->token.is(Token::Kind::Plus))
  {
    return evaluateExprTree(root->expr1, varTbl) + evaluateExprTree(root->expr2, varTbl);
  } 
  else if (root->token.is(Token::Kind::Minus)) 
  {
    return evaluateExprTree(root->expr1, varTbl) - evaluateExprTree(root->expr2, varTbl);
  } 
  else if (root->token.is(Token::Kind::Asterisk))
  {
    return evaluateExprTree(root->expr1, varTbl) * evaluateExprTree(root->expr2, varTbl);
  }
  else if (root->token.is(Token::Kind::Equal)) 
  {
    varTbl[root->expr1->token.lexeme] = evaluateExprTree(root->expr2, varTbl);
    return evaluateExprTree(root->expr2, varTbl);
  } 
  return BigInt();
}

} // namespace ds
