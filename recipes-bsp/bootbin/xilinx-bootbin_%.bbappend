do_compile:prepend() {
	if [ -n "${BIF_FILE_NAME}" ] && [ -n "${BIF_FILE_DIR}" ]; then
		cp ${BIF_FILE_DIR}/${BIF_FILE_NAME} ${BIF_FILE_PATH}
		if [ -n "${NKY_FILE_PATH}" ]; then
			cp ${NKY_FILE_PATH}/*.nky ${WORKDIR}
		fi
	fi
}
