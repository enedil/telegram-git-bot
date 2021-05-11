FROM fedora:33

RUN mkdir "/scripts"
COPY "external/seastar/install-dependencies.sh" "/scripts/deps.sh"

RUN /scripts/deps.sh

RUN mkdir /sourcetree
VOLUME /sourcetree

CMD /sourcetree/scripts/build.sh /sourcetree
