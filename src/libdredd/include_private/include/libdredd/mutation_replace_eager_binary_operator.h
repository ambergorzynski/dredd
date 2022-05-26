// Copyright 2022 The Dredd Project Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DREDD_MUTATION_REPLACE_EAGER_BINARY_OPERATOR_H
#define DREDD_MUTATION_REPLACE_EAGER_BINARY_OPERATOR_H

#include "clang/AST/Decl.h"
#include "clang/AST/Expr.h"
#include "clang/AST/PrettyPrinter.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "libdredd/mutation.h"

namespace dredd {

class MutationReplaceEagerBinaryOperator : public Mutation {
 public:
  MutationReplaceEagerBinaryOperator(clang::BinaryOperator* binary_operator,
                                     clang::FunctionDecl* enclosing_function);

  void Apply(int mutation_id, clang::Rewriter& rewriter,
             clang::PrintingPolicy& printing_policy) const override;

 private:
  clang::BinaryOperator* binary_operator_;
  clang::FunctionDecl* enclosing_function_;
};

}  // namespace dredd

#endif  // DREDD_MUTATION_REPLACE_EAGER_BINARY_OPERATOR_H