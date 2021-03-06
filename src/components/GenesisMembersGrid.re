module Styles = {
  open Css;

  let genesisCopy =
    style([
      unsafe("grid-area", "1 /1 / span 1 / span 2"),
      media(Theme.MediaQuery.tablet, [width(`rem(34.))]),
    ]);
  let sectionSubhead =
    merge([
      Theme.Type.sectionSubhead,
      style([
        fontSize(`px(19)),
        lineHeight(`rem(1.75)),
        marginTop(`rem(0.5)),
        marginBottom(`rem(2.)),
        letterSpacing(`pxFloat(-0.4)),
      ]),
    ]);
  let grid =
    style([
      marginTop(`rem(1.)),
      display(`grid),
      gridTemplateColumns([`rem(11.5), `rem(11.5)]),
      gridAutoRows(`rem(17.)),
      gridColumnGap(`rem(2.)),
      gridRowGap(`rem(1.)),
      media(
        Theme.MediaQuery.tablet,
        [gridTemplateColumns([`repeat((`num(3), `rem(11.5)))])],
      ),
      media(
        Theme.MediaQuery.desktop,
        [gridTemplateColumns([`repeat((`num(5), `rem(11.5)))])],
      ),
    ]);
};

[@react.component]
let make = (~genesisMembers, ~switchModalState, ~setCurrentIndexAndMembers) => {
  <>
    <Spacer height=4. />
    <div className=Styles.genesisCopy>
      <h2 className=Theme.Type.h3> {React.string("Genesis Members")} </h2>
      <p className=Styles.sectionSubhead>
        {React.string(
           "Meet the node operators, developers, and community builders making Mina happen.",
         )}
      </p>
    </div>
    <div className=Styles.grid>
      {React.array(
         genesisMembers
         |> Array.map((member: ContentType.GenericMember.t) => {
              <div
                key={member.name}
                onClick={_ => {
                  switchModalState();
                  setCurrentIndexAndMembers(member, genesisMembers);
                }}>
                <SmallCard member />
              </div>
            }),
       )}
    </div>
  </>;
};
