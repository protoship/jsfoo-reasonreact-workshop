[@react.component]
let make = (~shortText, ~onChange) =>
  <label>
    <input
      className="w-full outline-none bg-transparent text-2xl leading-loose"
      type_="text"
      placeholder="Type your question here..."
      size=50
      value={shortText |> ShortText.title}
      onChange={event =>
        event->ReactEvent.Form.target##value
        |> ShortText.setTitle(shortText)
        |> onChange
      }
    />
  </label>;