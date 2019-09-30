[@react.component]
let make = () => {
  let backgroundImage = Image.bg0;
  <div
    className="h-full"
    style={ReactDOMRe.Style.make(
      ~backgroundImage={j|url("$backgroundImage")|j},
      ~backgroundSize="70% 70%",
      ~backgroundPosition="center",
      ~backgroundRepeat="no-repeat",
      (),
    )}
  />;
};