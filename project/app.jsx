import "./styles.css";
import { convertToPostfix } from "./utils/Postfix.js";
import { evaluatePostfix } from "./utils/Evaluation.js";
import { useState } from "react";
export default function App() {
  const [infixExpression, setInfixExpression] = useState("");
  const [postfixExpression, setPostfixExpression] = useState("");
  const [evaluatedResult, setEvaluatedResult] = useState("");
  const handleConversion = () => {
    const postfix = convertToPostfix(infixExpression);
    setPostfixExpression(postfix);

    const result = evaluatePostfix(postfix);
    setEvaluatedResult(result);
  };
  return (
    <div className="App">
      <h1>Postfix to infix converter</h1>
      <hr />
      <label htmlFor="text">Infix Expression</label>
      <input
        type="text"
        placeholder="Enter Infix Expression"
        value={infixExpression}
        onChange={(e) => setInfixExpression(e.target.value)}
      />
      <br />
      <label htmlFor="text">Postfix Expression</label>
      <textarea
        name="Postfix"
        id="postfix"
        readOnly
        value={postfixExpression}
      ></textarea>
      <br />
      <label htmlFor="text">Evaluated Answer</label>
      <textarea name="" id="" readOnly value={evaluatedResult}></textarea>
      <br />
      <button onClick={handleConversion}>Convert</button>
    </div>
  );
}
