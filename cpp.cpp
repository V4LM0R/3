
    import streamlit as st

def filtrar_emails(input_content):
    output_emails = []
    for line in input_content.splitlines():
        parts = line.strip().split(',')
        if len(parts) == 3:
            nombre, edad_str, email = parts
            try:
                edad = int(edad_str)
                if edad > 18:
                    output_emails.append(email)
            except ValueError:
                pass
    return output_emails

st.title("Filtrado de Emails")

uploaded_file = st.file_uploader("Elige un archivo", type="txt")

if uploaded_file is not None:
    input_content = uploaded_file.read().decode("utf-8")
    
    output_emails = filtrar_emails(input_content)
    
    st.write("Emails filtrados (mayores de 18 años):")
    for email in output_emails:
        st.write(email)
    
    # Opción para descargar los emails filtrados
    output_filename = "emails_filtrados.txt"
    with open(output_filename, "w") as output_file:
        for email in output_emails:
            output_file.write(email + "\n")
    
    st.download_button(
        label="Descargar emails filtrados",
        data="\n".join(output_emails),
        file_name=output_filename,
        mime="text/plain",
    )