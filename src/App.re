open Belt;

type action =
  | Add(FormItem.t)
  | Update(FormItem.t)
  | Delete(FormItem.t);

let reducer = (state, action) =>
  switch (action) {
  | Add(formItem) => state @ [formItem]
  | Update(formItem) =>
    state->List.map(x =>
      RandomId.eq(x |> FormItem.id, formItem |> FormItem.id) ? formItem : x
    )
  | Delete(formItem) =>
    state->List.keep(x =>
      !RandomId.eq(x |> FormItem.id, formItem |> FormItem.id)
    )
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, []);

  let onMouseClick = (action, event) => {
    event |> ReactEvent.Mouse.preventDefault;
    action |> dispatch;
  };

  let onUpdate = formItem => Update(formItem) |> dispatch;

  let headerView =
    <div
      className="bg-gray-800 text-white text-base leading-normal p-3 font-mono">
      <p> {React.string("Form Builder")} </p>
    </div>;

  let builderLeftView = {
    let onDelete = formItem => Delete(formItem) |> onMouseClick;

    let formItemBuilderViews = {
      state->List.map(formItem =>
        <FormItemBuilder
          key={formItem |> FormItem.id |> RandomId.toString}
          formItem
          onUpdate
          onDelete
        />
      )
      |> List.toArray
      |> React.array;
    };

    let addQuestionView = {
      let onAdd = formItem => Add(formItem) |> onMouseClick;
      let onAddOpinionScale = opinionScale =>
        FormItem.OpinionScale(opinionScale) |> onAdd;
      let onAddShortText = shortText =>
        FormItem.ShortText(shortText) |> onAdd;
      <div className="p-6 bg-gray-300">
        <p className="mb-4"> {React.string("Choose a question type: ")} </p>
        <AddButton
          text="Opinion Scale"
          icon=Icon.scaleAnswer
          onClick={
            OpinionScale.make(~title="", ~startsAtOne=true, ~steps=11)
            |> onAddOpinionScale
          }
        />
        <AddButton
          text="Short Text"
          icon=Icon.textAnswer
          onClick={ShortText.make(~title="") |> onAddShortText}
        />
      </div>;
    };

    <div
      className="bg-gray-400 py-6 px-12 overflow-y-scroll scrollbar-transparent">
      formItemBuilderViews
      addQuestionView
    </div>;
  };

  let previewRightView = {
    let preview =
      switch (state) {
      | [] => <EmptyPreview />
      | [_head, ..._rest] => <FormItemView formItems=state onUpdate />
      };

    <div className="overflow-y-scroll"> preview </div>;
  };

  <>
    headerView
    <div className="grid grid-2-3 h-content">
      builderLeftView
      previewRightView
    </div>
  </>;
};