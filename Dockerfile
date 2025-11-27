FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive

# Update repository ke server pusat (archive.ubuntu.com)
# Kita tambahkan --fix-missing buat jaga-jaga kalau internet putus nyambung
RUN apt-get update && apt-get install -y --fix-missing \
    openmpi-bin \
    libopenmpi-dev \
    build-essential \
    openssh-server \
    sudo

# Setting SSH (Standar)
RUN mkdir /var/run/sshd
RUN ssh-keygen -t rsa -f /root/.ssh/id_rsa -q -N ""
RUN cp /root/.ssh/id_rsa.pub /root/.ssh/authorized_keys
RUN echo "StrictHostKeyChecking no" >> /etc/ssh/ssh_config

WORKDIR /app
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]