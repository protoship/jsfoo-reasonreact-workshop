[@react.component]
let make = (~shortText, ~onChange) => {
  <label>
    <p className="font-thin text-3xl leading-normal mb-4">
      {shortText |> ShortText.title |> React.string}
    </p>
    <input
      className="outline-none p-2 text-2xl bg-gray-100"
      type_="text"
      size=40
      placeholder="Type your answer here..."
      value={shortText->ShortText.answer}
      onChange={event =>
        event->ReactEvent.Form.target##value
        |> ShortText.setAnswer(shortText)
        |> onChange
      }
    />
  </label>;
};